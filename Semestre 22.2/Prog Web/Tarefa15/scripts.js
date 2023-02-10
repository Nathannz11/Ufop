//Nathann Zini dos Reis 19.2.4007  
//Feito junto com Enya Santos

class Menu {
    constructor() {
      this.buttonContainer = document.querySelector('#menu');
      this.statusBar = document.querySelector('#status-bar');
      
      this.showButtonClicked = this.showButtonClicked.bind(this);
      this._onClick = this._onClick.bind(this);

      
      this.buttons = [
        new Button(this.buttonContainer, 'A', this._onClick),
        new Button(this.buttonContainer, 'B', this._onClick),
        new Button(this.buttonContainer, 'C', this._onClick)
      ];
      
    }
    
    showButtonClicked(buttonName) {
      this.statusBar.textContent = buttonName + ' was clicked';
    }

    _onClick(text) {
       this.showButtonClicked(text)
    }
}
  
  class Button {
    constructor(containerElement, text, onClick) {
      this.containerElement = containerElement;
      this.text = text;
      
      const button = document.createElement('button');
      button.textContent = text;
      button.addEventListener('click', () => onClick(text));
      this.containerElement.append(button);
    }
    

  }
  
  new Menu();