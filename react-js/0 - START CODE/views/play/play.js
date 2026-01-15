// DOMS ELEMENTS  ---------------------------------------------------------
const dom_quiz = document.querySelector("#quiz");
const dom_question = document.querySelector("#question");
const dom_choiceA = document.querySelector("#A");
const dom_choiceB = document.querySelector("#B");
const dom_choiceC = document.querySelector("#C");
const dom_choiceD = document.querySelector("#D");
const dom_score = document.querySelector("#score");
const dom_start = document.querySelector("#start");

dom_start.addEventListener("click", onStart);

// DATA  ---------------------------------------------------------
let questions = [
  {
    title: "What does HTML stand for?",
    choiceA: "Hi Thierry More Laught",
    choiceB: "How To move Left",
    choiceC: "Ho Theary Missed the Laundry !",
    choiceD: "Hypertext Markup Language",
    correct: "D",
  },
  {
    title: "What does CSS stand for?",
    choiceA: "Cisco and Super Start",
    choiceB: "Ci So Sa",
    choiceC: "Cascading Style Sheets ",
    choiceD: "I don't know !",
    correct: "C",
  },
  {
    title: "What does JS stand for?",
    choiceA: "Junior stars",
    choiceB: "Justing Star",
    choiceC: "Javascript",
    choiceD: "RonanScript",
    correct: "C",
  },
];
let runningQuestionIndex = 0;
let score = 0;

// FUNCTIONS ---------------------------------------------------------

// Hide a given element
function hide(element) {
  // TODO
  element.style.display = "none";
}

function show(element) {
  // TODO
  element.style.display = "block";
}

function onStart() {
  // Render the current question
  renderQuestion();

  // Display the quiz view,
  hide(dom_start);
  show(dom_quiz);
}

function renderQuestion() {
  // Render the current question on the quiz view
  let question = questions[runningQuestionIndex];

  dom_question.textContent = question.title;
  dom_choiceA.textContent = question.choiceA;
  dom_choiceB.textContent = question.choiceB;
  dom_choiceC.textContent = question.choiceC;
  dom_choiceD.textContent = question.choiceD;
}

function checkAnswer(answer) {
  // Update the score, display the next question or the score view
  if (runningQuestionIndex>=questions.length) { return; }
  let current = questions[runningQuestionIndex];
  if (answer === current.correct) {
    score+=1;
  }

  if (runningQuestionIndex<questions.length-1) {
    runningQuestionIndex++;
    renderQuestion();
  } else {
    runningQuestionIndex = questions.length;
    renderSCore();
  }
}

function renderSCore() {
  // calculate the amount of question percent answered by the user
  hide(dom_quiz);
  let max = questions.length;
  const percentToAdd = 100/max;
  let percent = percentToAdd*score;

  let finalScore = document.getElementById('score');
  finalScore.style.display = "block";

  finalScore.textContent = percent + "%";

  // choose the image based on the scorePerCent
  var img = document.getElementById('image');
  if (!img) {
    alert("image is null");
  } else if (percent===100) {
    img.src = 'https://media1.tenor.com/m/oExlwt8_0XwAAAAd/coding-what.gif';
  } else if(percent>=80) {
    img.src = '';
  } else if (percent>=60) {
    img.src = '';
  } else if (percent>=40) {
    img.src = '';
  } else if (percent>=20) {
    img.src = '';
  } else {
    img.src = 'https://media1.tenor.com/m/dofkOmsOZmwAAAAd/sliped-banana.gif';
  }
}

// FUNCTIONS ---------------------------------------------------------
show(dom_start);
hide(dom_quiz);
hide(dom_score);
