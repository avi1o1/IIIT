let isDefaultMode = true;
let isLiked = false;

function blogMode() {
    const newGradient = isDefaultMode
        ? '#3D9CAB'
        : '#2b2b2b';
    document.body.style.background = newGradient;
    document.body.classList.add('transition-effect');

    const modeIcon = document.getElementById('changeMode');
    const modic = isDefaultMode
        ? 'url("Resources/sun.png")'
        : 'url("Resources/moon.png")';
    modeIcon.style.backgroundImage = modic;
    modeIcon.classList.add('mode-transition-effect');

    isDefaultMode = !isDefaultMode;
}

const likeButton = document.getElementById('likeButton');
const likeCountSpan = document.getElementById('likeCount');
let comments = JSON.parse(localStorage.getItem('blog2comments')) || [];
let likeCount = localStorage.getItem('blog2likeCount');

if (!likeCount) {
    likeCount = 0;
}

updateLikeCount();
displayComments();

function updateLikeCount() {
    likeCountSpan.textContent = likeCount;
}

function clicked() {
    const buttonIcon = document.getElementById('icon');

    if (likeButton.classList.contains('liked')) {
        likeCount--;
        likeButton.classList.remove('liked');
        buttonIcon.classList.remove('fa-solid', 'fa-heart', 'fa-2xl');
        buttonIcon.classList.add('fa-regular', 'fa-heart', 'fa-2xl');
    }
    else {
        likeCount++;
        likeButton.classList.add('liked');
        buttonIcon.classList.remove('fa-regular', 'fa-heart', 'fa-2xl');
        buttonIcon.classList.add('fa-solid', 'fa-heart', 'fa-2xl');
    }

    isLiked = !isLiked;
    updateLikeCount();
    localStorage.setItem('blog2likeCount', likeCount);
}

likeButton.addEventListener('click', clicked);

function displayComments() {
    const commentList = document.getElementById('commentList');
    commentList.innerHTML = '';
    let commentCount = 0;
  
    comments.forEach(comment => {
        const li = document.createElement('li');
        li.textContent = comment;
        commentList.appendChild(li);
        commentCount++;
    });


    const commentCountSpan = document.getElementById('commentCount');
    commentCountSpan.textContent = commentCount;
    localStorage.setItem('commentCount', commentCount);
}

function postComment() {
    const commentInput = document.getElementById('commentInput');
    const commentText = commentInput.value.trim();
  
    if (commentText !== '') {
      comments.push(commentText);
      localStorage.setItem('blog2comments', JSON.stringify(comments));

      displayComments();
      commentInput.value = '';
    }
}
