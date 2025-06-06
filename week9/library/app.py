from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

app = Flask(__name__)

#db = SQL("sqlite:///history.db")

app.config["TEMPLATES   _AUTO_RELOAD"] = True

@app.route("/", methods=["GET"])
def index():
    string = random_string(1000)
    return render_template("index.html", placeholder=string)
