from flask import Flask, render_template, request

app = Flask(__name__)

def fib(n):
  a = 0
  b = 1
  for __ in range(n):
    a, b = b, a + b
  return a

@app.route('/', methods=['post', 'get'])

def index():
  message = ''
  if request.method == "POST":
    num = int(request.form.get('whatnum'))
    message = 'Число fib(' + str(num) + ') = ' + str(fib(num))
  return render_template('index.html', message=message)

if __name__ == "__main__":
  app.run(host="0.0.0.0")