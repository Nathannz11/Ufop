const PATH = 'https://api.dictionaryapi.dev/api/v2/entries/en';

class App {
  constructor() {
    this._onJsonReady = this._onJsonReady.bind(this);
    this._onSubmit = this._onSubmit.bind(this);

    const form = document.querySelector('form');
    form.addEventListener('submit', this._onSubmit);
  }

  signup(user, password) {
    fetch('http://localhost:3000/user', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({user, password})
    })
    .then(response => console.log(response.data))
  }

  signin(user, password) {
    console.log(user, password)
  }

  _onSubmit(event) {
    const e = event.submitter.name
    event.preventDefault();
    const textUser = document.querySelector('#username');
    const textPassword= document.querySelector('#password');

    const user = encodeURIComponent(textUser.value);
    const password = encodeURIComponent(textPassword.value);

    if(e === "signup")
        this.signup(user, password);
    else if(e == "signin")
        this.signin(user, password);

  }

  _renderDefinitions() {
    const definitionsContainer = document.querySelector(
      '#definitions-container'
    );
    definitionsContainer.innerHTML = '';
    for (const meanings of this.definition.meanings) {
      new Dictionary(definitionsContainer, meanings);
    }
  }

  _onJsonReady(json) {
    this.definition = json[0];
    this._renderDefinitions();
  }

  _onResponse(response) {
    return response.json();
  }
}

const app = new App();
