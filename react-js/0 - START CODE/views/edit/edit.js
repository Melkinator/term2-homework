// DOMS ELEMENTS  ---------------------------------------------------------
const dom_questions_view = document.getElementById("questions-view");
const dom_questions_dialog = document.getElementById("questions-dialog");
const dom_createEditButton = document.getElementById("createEditButton");

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

let questionToEdit = null;

function hide(element) {
    element.style.display = "none";
}

function show(element) {
    element.style.display = "block";
}

function saveQuestion() {
    localStorage.setItem("questions", JSON.stringify(questions));
}

function loadQuestion() {
    let questionStorage = JSON.parse(localStorage.getItem("questions"));
    if (questionStorage!==null) {
        questions = questionStorage;
    }
}

function renderQuestion() {
    let questions_container = document.querySelector("#questions-container");
    if (questions_container) questions_container.remove();
    questions_container = document.createElement("div");
    questions_container.id = "questions-container";
    dom_questions_view.appendChild(questions_container);

    for (let i=0;i<questions.length;i++) {
        let question = questions[i];

        let card = document.createElement("div");
        card.className = "card";
        card.dataset.index = i;
        questions_container.appendChild(card);

        let questionInfo = document.createElement("div");
        questionInfo.className = "question-info";
        card.appendChild(questionInfo);

        let title = document.createElement("span");
        title.className = "title";
        title.textContent = question.title;
        questionInfo.appendChild(title);

        let action = document.createElement("div");
        action.className = "action";
        card.appendChild(action);

        let edit  = document.createElement("img");
        edit.src = 'https://media1.tenor.com/m/dofkOmsOZmwAAAAd/sliped-banana.gif';
        edit.addEventListener("click", editQuestion);
        action.appendChild(edit);

        let trash = document.createElement("img");
        trash.src = 'https://media1.tenor.com/m/dofkOmsOZmwAAAAd/sliped-banana.gif';
        trash.addEventListener("click", removeQuestion);
        action.appendChild(trash);
    }
}

function editQuestion(event) {
    questionToEdit = event.target.parentElement.parentElement.dataset.index;

    let question = questions[questionToEdit];
    document.getElementById("title").value = question.title;
    document.getElementById("choiceA").value = question.choiceA;
    document.getElementById("choiceB").value = question.choiceB;
    document.getElementById("choiceC").value = question.choiceC;
    document.getElementById("choiceD").value = question.choiceD;

    dom_createEditButton.textContent = "edit";
    show(dom_questions_dialog);
}

function removeQuestion(event) {
    let i = event.target.parentElement.parentElement.dataset.index;

    question.splice(i, 1);
    saveQuestion();
    renderQuestion();
}

function addQuestion() {
    show(dom_questions_dialog);
}

function cancel() {
    hide(dom_questions_dialog);
}

function create() {
    hide(dom_questions_dialog);

    if (questionToEdit!==null) {
        let editQuestion = questions[questionToEdit];
        editQuestion.title = document.getElementById("title").value;
        editQuestion.correct = "A";
        editQuestion.choiceA = document.getElementById("choiceA").value;
        editQuestion.choiceB = document.getElementById("choiceB").value;
        editQuestion.choiceC = document.getElementById("choiceC").value;
        editQuestion.choiceD = document.getElementById("choiceD").value;
    } else {
        let newQuestion = {};
        newQuestion.title = document.getElementById("title").value;
        newQuestion.correct = "A";
        newQuestion.choiceA = document.getElementById("choiceA").value;
        newQuestion.choiceB = document.getElementById("choiceB").value;
        newQuestion.choiceC = document.getElementById("choiceC").value;
        newQuestion.choiceD = document.getElementById("choiceD").value;
        questions.push(newQuestion);
    }
    saveQuestion();
    renderQuestion();
}

loadQuestion();

renderQuestion();