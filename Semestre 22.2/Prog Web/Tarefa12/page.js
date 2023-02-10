let contador = 0;

const text = document.createElement("p");
text.id = "text-counter";
document.body.insertBefore(text, document.body.childNodes[0]);

function counter(){
    text.textContent = "Number of images: " + (++contador);
}

function trocarImg(){
    const imgSrc = "https://www.melhoresdestinos.com.br/wp-content/uploads/2019/02/passagens-aereas-paris-capa2019-01.jpg";
    const img = document.querySelectorAll("img");
    
    img.forEach(
        (imgWeb) => {
            imgWeb.src = imgSrc;
            counter();
        }
    );
};

window.addEventListener("load", trocarImg);