# Proje: C++23 Modüler Uygulama

Modern C++23 özellikleri (C++20 named modules, source location, RAII) kullanan bir komut satırı uygulama iskeletidir.

## Build

```bash
bash scripts/build.sh   # Derleme
bash scripts/clean.sh   # Build dizinini temizle
```

Çıktı: `build/bin/app.exe`

## Proje Yapısı

```
src/
├── main.cpp
├── application/        # Uygulama çekirdeği ve CLI
│   ├── application.cppm/.cpp
│   └── cli.cppm/.cpp
├── logging/            # Dosya tabanlı loglama sistemi
│   ├── logging.cppm
│   └── logger.cpp
├── exception/          # İstisna yönetimi
│   └── exception.cppm
└── filesystem/         # Henüz implemente edilmedi
    └── filesystem.cppm/.cpp
```

## Teknoloji

- **Dil:** C++23 (`-std=c++23 -fmodules-ts`)
- **Derleyici:** GCC (g++)
- **Modül sistemi:** C++20 named modules (`.cppm` arayüz, `.cpp` implementasyon)
- **Bağımlılık:** Yalnızca standart kütüphane

## Kurallar

- Modül arayüzleri `.cppm`, implementasyonlar `.cpp` uzantılı olmalı
- Kaynak yönetimi için RAII kullan (`unique_ptr`, RAII sarmalayıcılar)
- Log mesajları `logger` üzerinden yazılmalı; `std::cout`/`fprintf` kullanma
- İstisna yakalamayı `exception::handle()` ile yap
- Yeni modüller için önce `.cppm` arayüz dosyasını oluştur, sonra `build.sh`'a ekle

## Log Sistemi

```cpp
// Logger oluşturma
logging::logger log{"uygulama.log"};

// Log seviyeleri: debug, info, warn, error, fatal
log.log(logging::level::info, "Mesaj");
```

- `std::source_location::current()` default parametre olarak tanımlı — explicit geçmeye gerek yok
- `std::chrono::system_clock::now()` de default — timestamp otomatik yakalanır

Log formatı: `[ISO8601 timestamp] [LEVEL] dosya:satır fonksiyon(): mesaj`
