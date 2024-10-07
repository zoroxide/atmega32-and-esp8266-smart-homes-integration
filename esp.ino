#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = " ";
const char* password = " ";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/ledOn", []() {
    Serial.write('A');
  });
  server.on("/motorOn", []() {
    Serial.write('B');
  });
  server.on("/relayOn", []() {
    Serial.write('C');
  });
  server.on("/relayOFF", []() {
    Serial.write('c');
  });
  server.on("/ledOFF", []() {
    Serial.write('a');
    server.send(200);
  });
  server.on("/motorOFF", []() {
    Serial.write('b');
  });

  server.on("/allON", []() {
    Serial.write('X');
  });

  server.on("/allOFF", []() {
    Serial.write('x');
  });
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Control Panel</h1>";
  html += "<div id='status'></div><br>";

  html += "<script>";
  html += "function sendRequest(endpoint) {";
  html += "  fetch(endpoint).then(() => {";
  html += "    document.getElementById('status').innerText = 'Done';";
  html += "  });";
  html += "}";
  html += "</script>";

  // Modify buttons to use the sendRequest function instead of changing location
  html += "<button onclick=\"sendRequest('/ledOn')\">Turn LED On</button><br><br>";
  html += "<button onclick=\"sendRequest('/motorOn')\">Turn Motor On</button><br><br>";
  html += "<button onclick=\"sendRequest('/relayOn')\">Turn Relay On</button><br><br><br><br>";
  html += "<button onclick=\"sendRequest('/ledOFF')\">Turn LED OFF</button><br><br>";
  html += "<button onclick=\"sendRequest('/motorOFF')\">Turn Motor OFF</button><br><br>";
  html += "<button onclick=\"sendRequest('/relayOFF')\">Turn Relay OFF</button><br><br><br>";
  html += "<button onclick=\"sendRequest('/allON')\">Turn All ON</button><br><br>";
  html += "<button onclick=\"sendRequest('/allOFF')\">Turn All OFF</button><br><br>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}
