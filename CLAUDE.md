# C++ Coding Style

## Форматирование
- Использовать `clang-format` с конфигом `.clang-format` (на основе WebKit)
- Запускать перед коммитом: `clang-format -i --style=file <files>`

## Синтаксис

### Struct вместо Class
Использовать `struct` по умолчанию. `class` только когда нужна инкапсуляция.

```cpp
// Правильно
struct config_error : std::error_category {
    const char* name() const noexcept override { return "config"; }
};

// Неправильно
class config_error : public std::error_category {
public:
    const char* name() const noexcept override { return "config"; }
};
```

### Designated Initializers
Использовать именованную инициализацию структур с trailing запятой:

```cpp
// Правильно
return app_config{
    .host = j["host"].get<std::string>(),
    .port = j["port"].get<int>(),
    .timeout_ms = j["timeout_ms"].get<int>(),
    .debug = j["debug"].get<bool>(),
    .database = db_cfg,
    .features = j["features"].get<std::vector<std::string>>(),
};

// Неправильно
return app_config{j["host"].get<std::string>(), j["port"].get<int>(), ...};
```

### Фигурные скобки для if/loop
Всегда использовать `{}` для условий и циклов:

```cpp
// Правильно
if (!file.is_open()) {
    ec = make_error_code(config_errc::file_not_found);
    return {};
}

// Неправильно
if (!file.is_open())
    return {};
```

## Архитектура

### Общий код
- Структуры данных и утилиты выносить в `config_common.hpp`
- Избегать дублирования кода между примерами

### Обработка ошибок
- Пробрасывать ошибки через слои с обогащением контекста
- Для каждого подхода (exceptions, error_code, expected, outcome, leaf) — отдельный файл

## Пример структуры
```
examples/load-json-config/
├── config_common.hpp    # Общие структуры и утилиты
├── config.json          # Тестовый конфиг
├── exceptions.cpp       # Исключения
├── errc.cpp            # std::error_code
├── expected.cpp        # std::expected
├── outcome.cpp         # boost::outcome
└── leaf.cpp            # boost::leaf
```
