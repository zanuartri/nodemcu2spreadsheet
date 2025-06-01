# 🚀 Kirim Data NodeMCU (ESP8266) ke Google Sheets via Google Apps Script

Proyek ini menghubungkan NodeMCU ESP8266 dengan Wi-Fi dan mengirimkan data suhu & kelembapan (dummy/random) ke Google Sheets menggunakan Google Apps Script sebagai endpoint HTTP.

## 🛠️ Peralatan yang Dibutuhkan

- NodeMCU ESP8266
- Kabel USB
- Komputer dengan Arduino IDE
- Akun Google
- **Tanpa sensor tambahan** (data dummy/random)

---

## 🔧 Instalasi

- Install [Arduino IDE](https://www.arduino.cc/en/software)
- Tambahkan Board ESP8266:
  - File > Preferences > Tambahkan URL Board Manager:  
    `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
  - Lalu ke Tools > Board > Boards Manager > Cari "esp8266" dan install

---

## 📄 Google Apps Script (Backend)

### 1. Buat Google Spreadsheet

- Buat spreadsheet baru, beri nama `Log Suhu`
- Tambahkan header: `Waktu`, `Suhu`, `Kelembapan`

### 2. Buat Script Baru

- File > Extensions > Apps Script
- Ganti kode dengan berikut:

```javascript
function doGet(e) {
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var sheet = ss.getSheets()[0];

  var waktu = new Date();
  var suhu = e.parameter.suhu || "N/A";
  var kelembapan = e.parameter.kelembapan || "N/A";

  sheet.appendRow([waktu, suhu, kelembapan]);

  return ContentService.createTextOutput("Data masuk");
}
```
