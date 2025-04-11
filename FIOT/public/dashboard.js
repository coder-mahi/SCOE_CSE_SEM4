// public/dashboard.js

// Firebase script dependencies must be included in index.html

fetch('/firebase-config')
    .then(res => res.json())
    .then(firebaseConfig => {
        firebase.initializeApp(firebaseConfig);
        const database = firebase.database();
        const wasteRef = database.ref('waste_data');

        const dashboard = document.getElementById('dashboard');
        const noDataMessage = document.getElementById('noDataMessage');
        const addTestDataBtn = document.getElementById('addTestData');
        const clearDataBtn = document.getElementById('clearData');

        function addTestData() {
            const testData = {
                distance_cm: Math.floor(Math.random() * 15) + 5,
                moisture_percent: Math.floor(Math.random() * 100),
                waste_type: Math.random() > 0.5 ? "WET" : "DRY",
                timestamp: new Date().toISOString()
            };

            wasteRef.push(testData)
                .then(() => console.log("Test data added"))
                .catch(err => console.error("Error:", err));
        }

        function clearData() {
            if (confirm("Are you sure you want to delete all data?")) {
                wasteRef.remove()
                    .then(() => {
                        console.log("Data cleared");
                        dashboard.innerHTML = '';
                        noDataMessage.style.display = 'block';
                    })
                    .catch(err => console.error("Error clearing data:", err));
            }
        }

        function displayData(snapshot) {
            const data = snapshot.val();

            if (!data) {
                noDataMessage.style.display = 'block';
                return;
            }

            noDataMessage.style.display = 'none';
            dashboard.innerHTML = '';

            Object.entries(data).forEach(([key, entry]) => {
                const card = document.createElement('div');
                card.className = `card ${entry.waste_type.toLowerCase()}`;
                const date = new Date(entry.timestamp || parseInt(key));
                card.innerHTML = `
                    <h3>
                        <span class="status-indicator status-${entry.waste_type.toLowerCase()}"></span>
                        ${entry.waste_type} Waste
                    </h3>
                    <p><strong>Moisture:</strong> ${entry.moisture_percent}%</p>
                    <p><strong>Distance:</strong> ${entry.distance_cm} cm</p>
                    <p class="timestamp">${date.toLocaleString()}</p>
                `;
                dashboard.appendChild(card);
            });
        }

        addTestDataBtn.addEventListener('click', addTestData);
        clearDataBtn.addEventListener('click', clearData);
        wasteRef.on('value', displayData);
    })
    .catch(error => {
        console.error("Failed to load Firebase config:", error);
    });
