const express = require('express')
const cors = require('cors')


const app = express()
app.use(cors())
app.use(express.json())

app.post('/user', (req, res) => {
    const {user, password} = req.body
    return res.json({user, password})
})

app.listen(3000, () => console.log('Server is running on port 3000'))