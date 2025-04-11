const express = require('express');
const dotenv = require('dotenv');
const path = require('path');

dotenv.config(); // Load .env

const app = express();
const PORT = process.env.PORT || 3000;

// Serve static files from /public
app.use(express.static(path.join(__dirname, 'public')));

// Serve env variables as a JS file
app.get('/env.js', (req, res) => {
  res.setHeader('Content-Type', 'application/javascript');
  res.send(`
    window.env = {
      FIREBASE_API_KEY: "${process.env.FIREBASE_API_KEY}",
      FIREBASE_AUTH_DOMAIN: "${process.env.FIREBASE_AUTH_DOMAIN}",
      FIREBASE_DATABASE_URL: "${process.env.FIREBASE_DATABASE_URL}",
      FIREBASE_PROJECT_ID: "${process.env.FIREBASE_PROJECT_ID}",
      FIREBASE_STORAGE_BUCKET: "${process.env.FIREBASE_STORAGE_BUCKET}",
      FIREBASE_MESSAGING_SENDER_ID: "${process.env.FIREBASE_MESSAGING_SENDER_ID}",
      FIREBASE_APP_ID: "${process.env.FIREBASE_APP_ID}"
    };
  `);
});

app.listen(PORT, () => {
  console.log(`🚀 Server running at http://localhost:${PORT}`);
});
