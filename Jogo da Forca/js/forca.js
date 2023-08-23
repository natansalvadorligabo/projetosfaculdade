var palavra = [
    "objetos", "estrutura", "dados", "software", "engenharia", "interface", "computador",
];
function escolherPalavraAleatoria() {
    const random = Math.floor(Math.random() * palavra.length);
    return palavra[random];
}

palavra = escolherPalavraAleatoria();
const arrayPalavra = palavra.split("");
const arrayTamanho = palavra.length;
var mensagem = [];
var tentativas = 6;

console.log(palavra);

var botao = document.querySelector('#botao');

botao.addEventListener('click', () => {
    const letra = document.querySelector('#campo').value;
    let acertou = false; 

    for (let i = 0; i < arrayTamanho; i++) {
        if (arrayPalavra[i] === letra) {
            mensagem[i] = letra;
            acertou = true;
        }
    }

    if (!acertou) {
        tentativas--;
        trocaImagem(); 
        console.log("Tentativas restantes: " + tentativas);
    }

    document.querySelector('#letra').textContent = mensagem.join(" "); 
})

for (let i = 0; i < arrayTamanho; i++) {
    mensagem.push('_');
}

for (let i = 0; i < arrayTamanho; i++) {
    document.querySelector('#letra').textContent += mensagem[i];
}

function trocaImagem() {
    switch (tentativas) {
        case 0:
            document.querySelector("#imagemForca").src = 'img/forca6.png';
            console.log('Jogo encerrado!');
            location.reload();
            break;
        case 1:
            document.querySelector("#imagemForca").src = 'img/forca5.png';
            break;
        case 2:
            document.querySelector("#imagemForca").src = 'img/forca4.png';
            break;
        case 3:
            document.querySelector("#imagemForca").src = 'img/forca3.png';
            break;
        case 4:
            document.querySelector("#imagemForca").src = 'img/forca2.png';
            break;
        case 5:
            document.querySelector("#imagemForca").src = 'img/forca1.png';
            break;
        case 6:
            document.querySelector("#imagemForca").src = 'img/forca0.png';
            break;
        default:
            break;
    }
}
