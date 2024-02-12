# flask –app server run

from flask import Flask, request, jsonify

# instance of flask application
app = Flask(__name__)

# home route that returns below text when root url is accessed
@app.route("/")
def hello_world():
    return "Hello, World! From the Flask server.py."

# curl -X POST http://127.0.0.1:5000/submit -H "Content-Type: application/json" -d '{"key":"value"}'
@app.route('/submit', methods=['POST'])
def submit():
    # Ensure the request has JSON data
    if not request.is_json:
        return jsonify({"error": "Request must be JSON"}), 400

    # Get JSON data
    data = request.get_json()

    # Example processing (just echo back the data for demonstration)
    return jsonify({"received_data": data}), 200

if __name__ == '__main__':
   app.run()
