//Nathann Zini dos Reis 19.2.4007
//OBS: Fiz o código junto com a Enya

const button = document.querySelector('button');
const image = document.querySelector('img');

function handleChangeImage() {
  imagemAtual = image.getAttribute('src');
  if (imagemAtual === './imagem1.jpg') {
    image.src = './imagem2.jpg';
  } else {
    image.src = './imagem1.jpg';
  }
}

button.addEventListener('click', handleChangeImage);
