window.addEventListener('load', () => {
    // Load Firebase config from window.env
    const firebaseConfig = {
        apiKey: window.env.FIREBASE_API_KEY,
        authDomain: window.env.FIREBASE_AUTH_DOMAIN,
        databaseURL: window.env.FIREBASE_DATABASE_URL,
        projectId: window.env.FIREBASE_PROJECT_ID,
        storageBucket: window.env.FIREBASE_STORAGE_BUCKET,
        messagingSenderId: window.env.FIREBASE_MESSAGING_SENDER_ID,
        appId: window.env.FIREBASE_APP_ID,
    };

    // Initialize Firebase
    firebase.initializeApp(firebaseConfig);
    const database = firebase.database();
    const wasteRef = database.ref('waste_data');

    // DOM Elements
    const dashboard = document.getElementById('dashboard');
    const noDataMessage = document.getElementById('noDataMessage');
    const addTestDataBtn = document.getElementById('addTestData');
    const clearDataBtn = document.getElementById('clearData');

    // Function to add test data
    function addTestData() {
        const testData = {
            distance_cm: Math.floor(Math.random() * 15) + 5,
            moisture_percent: Math.floor(Math.random() * 100),
            waste_type: Math.random() > 0.5 ? "WET" : "DRY",
            timestamp: new Date().toISOString()
        };

        const newRef = wasteRef.push();
        newRef.set(testData);
    }

    // Function to clear all data
    function clearData() {
        if (confirm("Are you sure you want to delete all data?")) {
            wasteRef.remove().then(() => {
                dashboard.innerHTML = '';
                noDataMessage.style.display = 'block';
            });
        }
    }

    // Function to display all data on dashboard
    function displayData(snapshot) {
        const data = snapshot.val();

        dashboard.innerHTML = '';
        if (!data) {
            noDataMessage.style.display = 'block';
            return;
        }

        noDataMessage.style.display = 'none';

        Object.entries(data).forEach(([key, entry]) => {
            const card = document.createElement('div');
            card.className = `card ${entry.waste_type.toLowerCase()}`;

            const date = new Date(entry.timestamp || parseInt(key));
            card.innerHTML = `
                <h3><span class="status-indicator status-${entry.waste_type.toLowerCase()}"></span>
                ${entry.waste_type} Waste</h3>
                <p><strong>Moisture:</strong> ${entry.moisture_percent}%</p>
                <p><strong>Distance:</strong> ${entry.distance_cm} cm</p>
                <p class="timestamp">${date.toLocaleString()}</p>
            `;

            dashboard.appendChild(card);
        });
    }

    // Event listeners
    addTestDataBtn.addEventListener('click', addTestData);
    clearDataBtn.addEventListener('click', clearData);

    // Listen to Firebase data changes
    wasteRef.on('value', displayData);
});
