document.addEventListener('DOMContentLoaded', function() {
    let q1_passed = false;
    let q2_passed = false;
    let q3_passed = false;

    let answer = document.querySelector('#answer');
    let bgn_button = document.querySelector('#bgn');
    let chf_button = document.querySelector('#chf');
    let usd_button = document.querySelector('#usd');

    bgn_button.addEventListener('click', function() {
        bgn_button.style.backgroundColor = 'green';
        usd_button.style.backgroundColor = 'white';
        chf_button.style.backgroundColor = 'white';
        answer.textContent = 'Correct';
        answer.style.color = 'green';
        q1_passed = true;
        checkAllPassed();
    });

    chf_button.addEventListener('click', function() {
        chf_button.style.backgroundColor = 'red';
        bgn_button.style.backgroundColor = 'white';
        usd_button.style.backgroundColor = 'white';
        answer.textContent = 'Incorrect';
        answer.style.color = 'red';
        q1_passed = false;
    });

    usd_button.addEventListener('click', function() {
        usd_button.style.backgroundColor = 'red';
        chf_button.style.backgroundColor = 'white';
        bgn_button.style.backgroundColor = 'white';
        answer.textContent = 'Incorrect';
        answer.style.color = 'red';
        q1_passed = false;
    });
    //second question
    const input_container = document.getElementById('input-container');
    const submit_button = document.getElementById('submit');
    const answer2 = document.getElementById('answer2');

    submit_button.addEventListener('click', function(event) {
        event.preventDefault();


        const input_value = input_container.value.trim();
        if (input_value !== '') {
            if (input_value.toLowerCase() === 'sofia') {
                input_container.style.backgroundColor = 'green';
                answer2.textContent = 'Correct answer!';
                answer2.style.color = 'green';
                q2_passed = true;
                checkAllPassed();

                // setTimeout(function() {
                //     input_container.style.backgroundColor = 'white';
                //     answer2.textContent = '';
                //     answer2.style.color = 'white';
                // }, 2000);
            } else {
                input_container.style.backgroundColor = 'red';
                answer2.textContent = 'Incorrect answer!';
                answer2.style.color = 'red';
                q2_passed = false;

                setTimeout(function() {
                    input_container.style.backgroundColor = 'white';
                    answer2.textContent = '';
                    answer2.style.color = 'white';
                }, 2000);
            }
        }
    });

    //thirdquestion

    let stripe1_body = document.querySelector('.stripe1');
    let stripe2_body = document.querySelector('.stripe2');
    let stripe3_body = document.querySelector('.stripe3');
    let messageElement = document.querySelector('#message');


    function updateMessage() {
        let stripe1Color = window.getComputedStyle(stripe1_body).backgroundColor;
        let stripe2Color = window.getComputedStyle(stripe2_body).backgroundColor;
        let stripe3Color = window.getComputedStyle(stripe3_body).backgroundColor;

        // Check for Bulgaria flag (White, Green, Red)
        if (stripe1Color === 'rgb(255, 255, 255)' && stripe2Color === 'rgb(0, 128, 0)' && stripe3Color === 'rgb(255, 0, 0)') {
            messageElement.textContent = 'Congrats, that is the flag of Bulgaria';
            messageElement.style.color = 'green';
            q3_passed = true;
            checkAllPassed();
        }
        // Check for Hungary flag (Red, White, Green)
        else if (stripe1Color === 'rgb(255, 0, 0)' && stripe2Color === 'rgb(255, 255, 255)' && stripe3Color === 'rgb(0, 128, 0)') {
            messageElement.textContent = 'Oh, that is tha flag of Hungary';
            messageElement.style.color = 'red';
            q3_passed = false;
        }
        // Check for Iran flag (Green, White, Red)
        else if (stripe1Color === 'rgb(0, 128, 0)' && stripe2Color === 'rgb(255, 255, 255)' && stripe3Color === 'rgb(255, 0, 0)') {
            messageElement.textContent = 'Oh, that is tha flag of Iran';
            messageElement.style.color = 'red';
            q3_passed = false;
        }
        // Default message if none match
        else {
            messageElement.textContent = 'Hmm, what is that flag?';
            messageElement.style.color = 'black';
            q3_passed = false;
        }
    }

    // Event listeners for each button to change the flag colors and update the message
    document.querySelector('#white1').addEventListener('click', function() {
        stripe1_body.style.backgroundColor = 'white';
        updateMessage();
    });
    document.querySelector('#green1').addEventListener('click', function() {
        stripe1_body.style.backgroundColor = 'green';
        updateMessage();
    });
    document.querySelector('#red1').addEventListener('click', function() {
        stripe1_body.style.backgroundColor = 'red';
        updateMessage();
    });

    document.querySelector('#white2').addEventListener('click', function() {
        stripe2_body.style.backgroundColor = 'white';
        updateMessage();
    });
    document.querySelector('#green2').addEventListener('click', function() {
        stripe2_body.style.backgroundColor = 'green';
        updateMessage();
    });
    document.querySelector('#red2').addEventListener('click', function() {
        stripe2_body.style.backgroundColor = 'red';
        updateMessage();
    });

    document.querySelector('#white3').addEventListener('click', function() {
        stripe3_body.style.backgroundColor = 'white';
        updateMessage();
    });
    document.querySelector('#green3').addEventListener('click', function() {
        stripe3_body.style.backgroundColor = 'green';
        updateMessage();
    });
    document.querySelector('#red3').addEventListener('click', function() {
        stripe3_body.style.backgroundColor = 'red';
        updateMessage();
    });




    //POP UP



    const popup = document.getElementById('popup');

    function popit() {
        popup.classList.add('show'); // Add 'show' class to make the popup visible
        // setTimeout(function() {
        //     popup.classList.remove('show'); // Remove 'show' class to hide the popup
        // }, 6000); // Popup will disappear after 4 seconds
    }

    // Check if all questions are passed and show popup
    function checkAllPassed() {
        if (q1_passed && q2_passed && q3_passed) {
            popit();
        }
    }

    document.querySelector('.close-btn').addEventListener('click', function() {
        popup.classList.remove('show');
    });


});
