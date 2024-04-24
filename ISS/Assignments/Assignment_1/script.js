let isDefaultMode = true;

function toggleMode() {
    const shades = document.getElementsByClassName('coolShadow');
    const newColor = isDefaultMode
        ? '0px 4px 40px 0px rgba(0, 0, 0, 0.25)'
        : '0px 4px 40px 0px rgba(256, 256, 256, 0.25)';
    for (let i = 0; i < shades.length; i++) {
        shades[i].style.boxShadow = newColor;
        shades[i].classList.add('transition-effect');
    }

    const bgBox = document.getElementById('bg-box');
    const newGradient = isDefaultMode
        ? 'linear-gradient(#62D9CB, #105384)'
        : 'linear-gradient(128deg, #FFFFFF 7.37%, #222222 83.69%)';
    bgBox.style.background = newGradient;
    bgBox.classList.add('transition-effect');

    const dumbBox = document.getElementById('dumbBox');
    const newBG = isDefaultMode
        ? '#62D9CB'
        : '#858585';
    dumbBox.style.background = newBG;
    dumbBox.classList.add('transition-effect');

    const resumeBox = document.getElementById('resume');
    const resumeBG = isDefaultMode
        ? '#1F6A91'
        : '#696969';
    resumeBox.style.background = resumeBG;
    resumeBox.classList.add('transition-effect');

    const nameBox = document.getElementById('name');
    const nameImg = isDefaultMode
        ? 'url("Resources/namie.png")'
        : 'url("Resources/namie_bw.png")';
    nameBox.style.backgroundImage = nameImg;
    nameBox.classList.add('transition-effect');

    const backG = document.getElementById('bigBoy');
    const bg = isDefaultMode
        ? '#EDEDED'
        : '#2B2B2B';
    backG.style.background = bg;
    backG.classList.add('transition-effect');

    const lN = document.getElementById('linkedin');
    const licon = isDefaultMode
        ? 'url("Resources/white_linkedin.png")'
        : 'url("Resources/black_linkedin.png")';
    lN.style.backgroundImage = licon;
    lN.classList.add('transition-effect');

    const gN = document.getElementById('github');
    const gicon = isDefaultMode
        ? 'url("Resources/white_github.png")'
        : 'url("Resources/black_github.png")';
    gN.style.backgroundImage = gicon;
    gN.classList.add('transition-effect');

    const mN = document.getElementById('mail');
    const micon = isDefaultMode
        ? 'url("Resources/white_mail.png")'
        : 'url("Resources/black_mail.png")';
    mN.style.backgroundImage = micon;
    mN.classList.add('transition-effect');

    const modeIcon = document.getElementById('changeMode');
    const modic = isDefaultMode
        ? 'url("Resources/sun.png")'
        : 'url("Resources/moon.png")';
    modeIcon.style.backgroundImage = modic;
    modeIcon.classList.add('mode-transition-effect');

    isDefaultMode = !isDefaultMode;
}

function urmomgey() {
    document.getElementById("menu-box").style.marginLeft = window.innerWidth * 0.5 - 578 + "px";
    document.getElementById("menu-box").style.marginTop = window.innerHeight * 0.5 - 275 + "px";
    document.getElementById("dumbBox").style.marginLeft = window.innerWidth * 0.5 + 225 + "px";
    document.getElementById("dumbBox").style.marginTop = window.innerHeight * 0.5 - 400 + "px";
    document.getElementById("resume").style.marginLeft = window.innerWidth * 0.5 - 297 + "px";
    document.getElementById("resume").style.marginTop = window.innerHeight * 0.5 + 361 + "px";
}

urmomgey();
window.addEventListener("resize", urmomgey);

function meButton() {
    window.open('index.html', '_self');
}
