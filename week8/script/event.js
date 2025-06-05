function changeColorEvent(event) {
    var triggerObj = event.srcElement;
    document.getElementById('colorDiv').style.backgroundColor = triggerObj.innerHTML.toLowerCase();
}