Program ini berfungsi untuk **mengontrol dua relay** (bisa diperluas sampai empat) menggunakan **perintah dari Serial Monitor**.
Jadi kamu bisa menyalakan atau mematikan masing-masing relay dengan mengetik angka tertentu di Serial Monitor Arduino IDE.

---

## ⚙️ **2. Komponen yang Digunakan**

| Komponen                               | Jumlah | Fungsi                                         |
| -------------------------------------- | ------ | ---------------------------------------------- |
| NodeMCU ESP8266                        | 1      | Mikrokontroler utama                           |
| Modul Relay 2 channel (atau 4 channel) | 1      | Saklar elektronik untuk mengontrol beban AC/DC |
| Kabel jumper                           | -      | Penghubung                                     |
| Power supply 5V                        | 1      | Daya untuk relay                               |

---

## 🔌 **3. Wiring / Skema Koneksi**

### 🟦 **NodeMCU ke Modul Relay**

| Pin NodeMCU | Pin Relay | Keterangan                          |
| ----------- | --------- | ----------------------------------- |
| D1 (GPIO5)  | IN1       | Kontrol Relay 1                     |
| D2 (GPIO4)  | IN2       | Kontrol Relay 2                     |
| 3V3         | VCC       | Daya logika relay (jika relay 3.3V) |
| GND         | GND       | Ground bersama                      |

> ⚠️ **Catatan penting:**
>
> * Jika modul relay kamu **5V**, maka sebaiknya gunakan **VCC 5V** dari sumber eksternal, bukan 3V3 NodeMCU.
> * Pastikan **GND NodeMCU dan GND power relay** terhubung bersama.

---

### ⚫ **Relay ke Beban (misal Lampu DC/AC)**

| Relay Pin | Keterangan                                |
| --------- | ----------------------------------------- |
| COM       | Masuk dari sumber listrik (positif/line)  |
| NO        | Terhubung ke beban (nyala saat relay ON)  |
| NC        | Terhubung ke beban (nyala saat relay OFF) |

---

## 📜 **4. Penjelasan Program**

### 🔹 Bagian Deklarasi Pin

```cpp
#define RELAY1 5   // GPIO5 (D1)
#define RELAY2 4   // GPIO4 (D2)
```

Menentukan pin mana di NodeMCU yang digunakan untuk mengontrol relay.

---

### 🔹 Variabel Status Relay

```cpp
bool relay1State = LOW;
bool relay2State = LOW;
```

Variabel ini menyimpan **status terakhir** relay (nyala atau mati).

* `HIGH` = ON
* `LOW` = OFF

---

### 🔹 Fungsi setup()

```cpp
pinMode(RELAY1, OUTPUT);
pinMode(RELAY2, OUTPUT);
digitalWrite(RELAY1, relay1State);
digitalWrite(RELAY2, relay2State);
```

* Menetapkan pin sebagai output.
* Memastikan semua relay **mati (LOW)** saat awal program berjalan.

Kemudian ditampilkan petunjuk di Serial Monitor:

```cpp
Serial.println("1 = Relay1 ON, 2 = Relay2 ON, ...");
```

---

### 🔹 Fungsi loop()

Program terus membaca input dari **Serial Monitor**:

```cpp
if (Serial.available()) {
  char perintah = Serial.read();
  switch (perintah) {
    case '1': ... case '4': ...
  }
}
```

Artinya:

* Saat kamu ketik angka **1** → `Relay1` ON
* Saat kamu ketik angka **2** → `Relay2` ON
* Saat kamu ketik angka **3** → `Relay1` OFF
* Saat kamu ketik angka **4** → `Relay2` OFF

Dan hasilnya akan muncul di Serial Monitor:

```
Relay1 ON
Relay2 OFF
```

---

## 💡 **5. Cara Menguji**

1. Upload program ke **NodeMCU**.
2. Buka **Serial Monitor** (baudrate 115200).
3. Ketik salah satu perintah berikut:

   * `1` → Relay1 ON
   * `2` → Relay2 ON
   * `3` → Relay1 OFF
   * `4` → Relay2 OFF
4. Lihat LED indikator pada relay menyala/mati sesuai perintah.

---

## 🔧 **6. Contoh Pengembangan Selanjutnya**

Program ini bisa kamu kembangkan menjadi:

* 🔹 **Kontrol relay via Blynk IoT**
  (menggantikan perintah Serial dengan tombol di aplikasi)
* 🔹 **Kontrol otomatis berdasarkan sensor**
  (misal: relay aktif jika suhu tinggi)
* 🔹 **Integrasi dengan Firebase / Web Dashboard**

---

Apakah kamu ingin saya bantu **modifikasi program ini agar bisa dikontrol lewat Blynk IoT** juga (misalnya dengan tombol ON/OFF di HP)?
Kalau ya, saya bisa tuliskan versi lengkapnya dengan Virtual Pin dan koneksi WiFi.
