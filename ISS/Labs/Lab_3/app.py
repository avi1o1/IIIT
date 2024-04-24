import os
import json
from flask import Flask, redirect, url_for, request, render_template
from cryptography.fernet import Fernet
key = Fernet.generate_key()
fernet = Fernet(key)

app = Flask(__name__)

@app.route('/')
def begin():
    return render_template('loginpage.html')

@app.route('/success/<name>')
def success(name):
   return "Welcome %s! <br> Your ID has been created." %name

@app.route('/loginpage', methods = ['POST', 'GET'])
def login():
   if request.method == 'POST':
        username = request.form['nm']
        usermail = request.form['ml']
        userpwd = str(fernet.encrypt(request.form['pwd'].encode()).decode())
        user_dict = {"username": username, "usermail": usermail, "userpwd": userpwd}

        if not os.path.exists("users.txt"):
            with open("users.txt", 'w') as file:
                initial_data = {"userdata": []}
                json.dump(initial_data, file, indent=4)

        with open("users.txt", 'r+') as file:
            data = json.load(file)
            data["userdata"].append(user_dict)

            file.seek(0)
            json.dump(data, file, indent = 4)

        return redirect(url_for('success', name=username))

@app.route('/user/<id>')
def details(id):
   with open("users.txt", 'r') as file:
        data = json.load(file)

        for user in data["userdata"]:
            if user["username"] == id:
                txt = 'Username : ' + user["username"] + '<br><br> Usermail : ' + user["usermail"] + '<br><br> Userpwd : ' + user["userpwd"]
                return txt
        
        return "User doesn't exist"

if __name__ == '__main__':
    app.run(debug = True)

