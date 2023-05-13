const express = require('express');
const path = require('path')
const cors = require('cors');
const fs = require("fs");

const PORT = 3054;
const app = express();


app.use(express.json());
app.use(cors());
app.use(express.static(path.join(__dirname, 'views')))


app.post('/signin', (req, res) => {
    const { username, password } = req.body;
    fs.readFile(path.join(__dirname, 'data/users.json'), function(err, data) {
        if (err) throw err;

        const users = JSON.parse(data);
        const user = users.find((user) => user.username === username && user.password === password);
        return res.json({ user });
        
    });
})

app.post('/signup', (req, res) => {
    const { username, password } = req.body;
    const users = require("./data/users");
    const user = {
        username,
        password
    };

    const userIndex = users.findIndex((user) => user.username === username && user.password === password);
    if(userIndex !== -1) {
        users[userIndex] = user;
        return res.json({ user });
    }

    users.push(user);
    fs.writeFile(path.join(__dirname, 'data/users.json'), JSON.stringify(users), err => {
        if (err) throw err; 

        res.status(201);
        return res.json({ user });
    });
})

app.listen(PORT, () => console.log('Serving on port ' + PORT));