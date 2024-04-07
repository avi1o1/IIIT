var format = 1;

function classKabKhatamHogi(format) {
    let raw = new Date()
    let month = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

    let hrs = raw.getHours();
    let min, sec;

    if (raw.getMinutes() < 10) {
        min = '0' + raw.getMinutes();
    }
    else {
        min = raw.getMinutes();
    }

    if (raw.getSeconds() < 10) {
        sec = '0' + raw.getSeconds();
    }
    else {
        sec = raw.getSeconds();
    }
    
    let time;
    if (format > 0) {
        time = `${hrs} : ${min} : ${sec}`;
    }
    else {
        if (hrs >= 12) {
            if (hrs-12 < 10) {
                hrs = '0' + (hrs-12);
            }
            time = `${hrs} : ${min} : ${sec} PM`; 
        }
        else {
            if (hrs-12 < 10) {
                hrs = '0' + (hrs-12);
            }
            time = `${hrs} : ${min} : ${sec} AM`;
        }
    }
    let day = raw.getDate() + ' ' + month[raw.getMonth()] + ', ' + raw.getFullYear();

    const time_placeholder = document.getElementById("time");
    time_placeholder.textContent = time;

    const date_placeholder = document.getElementById("day");
    date_placeholder.textContent = day;


function changeFormat() {
    format *= -1;
    setInterval(() => classKabKhatamHogi(format), 100)
}

setInterval(() => classKabKhatamHogi(format), 100);}
