from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET","POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", placeholder=request.form.get("name", "world"))
        #request.args will look at GET only, so it cannot get the value that the user type in which is POST


