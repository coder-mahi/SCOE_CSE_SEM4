// Initialize Firebase and EmailJS from config.js
firebase.initializeApp(window.firebaseConfig);
emailjs.init(window.emailjsConfig.publicKey);

// Firebase database reference
const database = firebase.database();
const wasteRef = database.ref('waste_bin_data');

// DOM elements
const dashboard = document.getElementById('dashboard');
const noDataMessage = document.getElementById('noDataMessage');
const addTestDataBtn = document.getElementById('addTestData');
const clearDataBtn = document.getElementById('clearData');
const chartsRow = document.getElementById('chartsRow');
const currentTimeEl = document.getElementById('currentTime');

// Stats elements
const totalBinsEl = document.getElementById('totalBins');
const alertBinsEl = document.getElementById('alertBins');
const fullBinsEl = document.getElementById('fullBins');
const avgFillEl = document.getElementById('avgFill');

// Chart setup
let fillLevelChart;
const previousBinStatus = {}; // Track bin states for email alerts

// Update current time
function updateCurrentTime() {
    const now = new Date();
    currentTimeEl.textContent = now.toLocaleString();
}

setInterval(updateCurrentTime, 1000);
updateCurrentTime();

function initializeChart() {
    const ctx = document.getElementById('fillLevelChart').getContext('2d');
    
    fillLevelChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['0-25%', '26-50%', '51-75%', '76-100%'],
            datasets: [{
                label: 'Number of Bins',
                data: [0, 0, 0, 0],
                backgroundColor: [
                    '#2ecc71',
                    '#3498db',
                    '#f39c12',
                    '#e74c3c'
                ],
                borderWidth: 0,
                borderRadius: 5
            }]
        },
        options: {
            responsive: true,
            plugins: {
                legend: {
                    display: false
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    ticks: {
                        precision: 0
                    }
                }
            }
        }
    });
}

function updateChart(data) {
    if (!data) return;
    
    const fillLevels = [0, 0, 0, 0];
    
    Object.values(data).forEach(bin => {
        const fillPercentage = bin.fill_percentage || 0;
        
        if (fillPercentage <= 25) fillLevels[0]++;
        else if (fillPercentage <= 50) fillLevels[1]++;
        else if (fillPercentage <= 75) fillLevels[2]++;
        else fillLevels[3]++;
    });
    
    if (fillLevelChart) {
        fillLevelChart.data.datasets[0].data = fillLevels;
        fillLevelChart.update();
    }
}

function sendBinAlert(binId, fillPercentage) {
    const templateParams = {
        to_email: "contact.shindemahesh2112@gmail.com",
        email: "creatormahi1@gmail.com",
        bin_id: binId,
        fill_percentage: fillPercentage
    };

    emailjs.send(
        window.emailjsConfig.serviceId, 
        window.emailjsConfig.templateId, 
        templateParams
    )
    .then(() => console.log(`Alert sent for Bin ${binId}`))
    .catch(error => console.error('Email failed:', error));
}

function addTestData() {
    const binId = Math.floor(Math.random() * 9000) + 1000;
    const fillPercentage = Math.floor(Math.random() * 100);
    const isFull = fillPercentage > 75;
    
    const testData = {
        "alert": Math.random() > 0.7,
        "distance_cm": Math.floor(Math.random() * 50) + 5,
        "fill_percentage": fillPercentage,
        "status": isFull ? "Full" : "Not Full",
        "timestamp": new Date().getTime()
    };

    wasteRef.child(binId).set(testData)
        .then(() => console.log("Test data added for bin", binId))
        .catch(error => console.error("Error adding test data:", error));
}

function clearData() {
    if (confirm("Are you sure you want to delete all data?")) {
        wasteRef.remove()
            .then(() => {
                console.log("Data cleared");
                dashboard.innerHTML = '';
                noDataMessage.style.display = 'block';
                chartsRow.style.display = 'none';
                updateStats(null);
            })
            .catch(error => console.error("Error clearing data:", error));
    }
}

function updateStats(data) {
    if (!data) {
        totalBinsEl.textContent = '0';
        alertBinsEl.textContent = '0';
        fullBinsEl.textContent = '0';
        avgFillEl.textContent = '0%';
        return;
    }
    
    const binEntries = Object.entries(data);
    const totalBins = binEntries.length;
    let alertBins = 0;
    let fullBins = 0;
    let totalFill = 0;
    
    binEntries.forEach(([_, binData]) => {
        if (binData.alert) alertBins++;
        if (binData.status && binData.status.toLowerCase() === 'full') fullBins++;
        totalFill += binData.fill_percentage || 0;
    });
    
    const avgFill = totalBins > 0 ? Math.round(totalFill / totalBins) : 0;
    
    totalBinsEl.textContent = totalBins;
    alertBinsEl.textContent = alertBins;
    fullBinsEl.textContent = fullBins;
    avgFillEl.textContent = `${avgFill}%`;
}

function displayData(snapshot) {
    const data = snapshot.val();
    
    if (!data) {
        noDataMessage.style.display = 'block';
        chartsRow.style.display = 'none';
        updateStats(null);
        return;
    }
    
    noDataMessage.style.display = 'none';
    chartsRow.style.display = 'grid';
    dashboard.innerHTML = '';
    
    if (!fillLevelChart) {
        initializeChart();
    }
    
    Object.entries(data).forEach(([binId, binData]) => {
        // Adjust distance by subtracting 17cm
        const adjustedDistance = Math.max(0, (binData.distance_cm || 0) - 17);
        
        // Calculate fill percentage based on adjusted distance (assuming max distance is 30cm)
        const maxDistance = 30;
        const calculatedFillPercentage = Math.min(100, Math.max(0, 
            Math.round(100 - (adjustedDistance / maxDistance * 100))
        ));
        
        // Determine status based on calculated fill percentage
        const isFull = calculatedFillPercentage >= 75;
        const isAlert = calculatedFillPercentage >= 90;
        const status = isFull ? "Full" : "Not Full";
        
        // Check if bin just became full or in alert
        const wasFull = previousBinStatus[binId]?.wasFull || false;
        const wasAlert = previousBinStatus[binId]?.wasAlert || false;
        
        if (!wasFull && isFull) {
            sendBinAlert(binId, calculatedFillPercentage);
        }
        
        if (!wasAlert && isAlert) {
            sendBinAlert(binId, calculatedFillPercentage);
        }
        
        // Update previous status
        previousBinStatus[binId] = { wasFull: isFull, wasAlert: isAlert };

        // Create bin card
        const card = document.createElement('div');
        card.className = 'card';
        
        const statusClass = isAlert ? 'alert' : status.toLowerCase().replace(' ', '-');
        const date = new Date(binData.timestamp || parseInt(binId));
        
        card.innerHTML = `
            <div class="card-status status-${statusClass}"></div>
            <div class="card-body">
                ${isAlert ? '<div class="alert-badge"><i class="fas fa-exclamation-triangle"></i> ALERT</div>' : ''}
                <div class="bin-header">
                    <div class="bin-id">Bin #${binId}</div>
                    <div class="bin-status">
                        <span class="status-indicator status-${statusClass}"></span>
                        ${status}
                    </div>
                </div>
                
                <div class="fill-meter">
                    <div class="fill-level" style="width: ${calculatedFillPercentage}%"></div>
                </div>
                
                <div class="card-details">
                    <div class="detail-item">
                        <div class="detail-value">${calculatedFillPercentage}%</div>
                        <div class="detail-label">FILL LEVEL</div>
                    </div>
                    <div class="detail-item">
                        <div class="detail-value">${adjustedDistance} cm</div>
                        <div class="detail-label">DISTANCE</div>
                    </div>
                </div>
                
                <div class="timestamp"><i class="far fa-clock"></i> ${date.toLocaleString()}</div>
            </div>
        `;
        
        dashboard.appendChild(card);
    });
    
    updateStats(data);
    updateChart(data);
}

// Event listeners
addTestDataBtn.addEventListener('click', addTestData);
clearDataBtn.addEventListener('click', clearData);
wasteRef.on('value', displayData);