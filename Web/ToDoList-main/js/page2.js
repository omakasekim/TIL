var taskInput = document.getElementById("new-task");
var addButton = document.getElementsByTagName("button")[0];
var incompleteTasksHolder = document.getElementById("incomplete-tasks");
var completedTasksHolder = document.getElementById("completed-tasks");

//New Task List Item
var createNewTaskElement = function (taskString) {
  //Create List Item
  var listItem = document.createElement("li");

  //input (checkbox)
  var checkBox = document.createElement("input");
  //label
  var label = document.createElement("label");
  //input (text)
  var editInput = document.createElement("input");
  //button.edit
  var editButton = document.createElement("button");
  //button.delete
  var deleteButton = document.createElement("button");

  //Each element, needs modifying

  checkBox.type = "checkbox";
  editInput.type = "text";
  editButton.innerText = "Edit";
  editButton.className = "edit";
  deleteButton.innerText = "Delete";
  deleteButton.className = "delete";
  label.innerText = taskString;

  //Each elemts need appending
  listItem.appendChild(checkBox);
  listItem.appendChild(label);
  listItem.appendChild(editInput);
  listItem.appendChild(editButton);
  listItem.appendChild(deleteButton);

  return listItem;
};

//Add a new task
var addTask = function () {
  console.log("Add task");
  // When button is pressed
  // Create new list item with the text from the new task
  var listItem = createNewTaskElement(taskInput.value);
  //Append listItem to incompleteTasksHolder
  if (taskInput.value.length > 0) {
    incompleteTasksHolder.appendChild(listItem);
    bindTaskEvents(listItem, taskCompleted);
    taskInput.value = "";
  }
};

// Edit an existing task
var editTask = function () {
  console.log("Edit task");

  var listItem = this.parentNode;
  var editButton = this;
  var editInput = listItem.querySelector("input[type=text]");
  var label = listItem.querySelector("label");

  var containsClass = listItem.classList.contains("editMode");

  //if the class of the parent is .editMode
  if (containsClass) {
    //Switch from .editMode
    //Label text become input's (text) value
    label.innerText = editInput.value;
    editButton.innerText = "Edit";
  } else {
    //switch to .editMode
    //input (text) value becomes label's text
    editInput.value = label.innerText;
    editButton.innerText = "Save";
  }
  //Toggle .editMode on the li
  listItem.classList.toggle("editMode");
};

// Delete an existing task
var deleteTask = function () {
  console.log("Delete task");
  var listItem = this.parentNode;
  var ul = listItem.parentNode;
  //Remove the parent <li> from ul
  ul.removeChild(listItem);
};

// Mark a task a task as complete
var taskCompleted = function () {
  console.log("Task complete");
  //Append the task li to the #completed-tasks
  var listItem = this.parentNode;
  completedTasksHolder.appendChild(listItem);
  bindTaskEvents(listItem, taskIncomplete);
};

// Mark a task as incomplete
var taskIncomplete = function () {
  console.log("Task incomplete");
  //Append the task li to #incomplete-tasks
  var listItem = this.parentNode;
  incompleteTasksHolder.appendChild(listItem);
  bindTaskEvents(listItem, taskCompleted);
};

var bindTaskEvents = function (taskListItem, checkBoxEventHandler) {
  console.log("Bind list item events");
  //select taskListItems's children
  var checkBox = taskListItem.querySelector("input[type=checkbox]");
  var editButton = taskListItem.querySelector("button.edit");
  var deleteButton = taskListItem.querySelector("button.delete");

  //bind editTask to edit button
  editButton.onclick = editTask;

  //bind deleteTask to the delete button
  deleteButton.onclick = deleteTask;

  //bind checkboxEventHandler to the checkbox
  checkBox.onchange = checkBoxEventHandler;
};

//Set the click handler to the addTask function
addButton.addEventListener("click", addTask);

//cycle over incompleteTasksHolder ul list items
for (var i = 0; i < incompleteTasksHolder.children.length; i++) {
  //bind events to list item's children (taskCompleted)
  bindTaskEvents(incompleteTasksHolder.children[i], taskCompleted);
}

//cycle over completedTasksHolder ul list items
for (var i = 0; i < completedTasksHolder.children.length; i++) {
  //bind events to list item's children (taskIncomplete)
  bindTaskEvents(completedTasksHolder.children[i], taskIncomplete);
}