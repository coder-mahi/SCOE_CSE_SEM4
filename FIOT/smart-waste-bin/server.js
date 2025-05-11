const express = require('express');
const path = require('path');

const app = express();

// Serve static files from public directory
app.use(express.static(path.join(__dirname, 'public')));

// Serve config.js
app.get('/config.js', (req, res) => {
  res.sendFile(path.join(__dirname, 'config.js'));
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});

