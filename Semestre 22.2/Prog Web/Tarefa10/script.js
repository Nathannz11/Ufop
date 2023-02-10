//Nathann Zini dos Reis 19.2.4007

const image = document.querySelector('img');
const contador = document.querySelector('p.contador');
const hora = document.querySelector('p.hora');
const title = document.querySelector('h2');
let cont = 0;

function handleChangeImage() {
  imagemAtual = image.getAttribute('src');
  if (imagemAtual === './oppened_door.png') {
    image.src = './closed_door.png';
    image.alt = 'Porta Fechada';
    title.textContent = 'Porta Fechada';
    contador.textContent = 'Contador:' + ++cont;
    hora.textContent = Date(Date.now());
  } else {
    image.src = './oppened_door.png';
    image.alt = 'Porta Aberta';
    title.textContent = 'Porta Aberta';
    contador.textContent = 'Contador:' + ++cont;
    hora.textContent = Date(  Date.now());
  }
}

image.addEventListener('click', handleChangeImage);
