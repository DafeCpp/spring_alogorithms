# 🔧 Устранение проблем с AI Workflow

## Проблема: "Resource not accessible by integration"

### Быстрое решение

Если вы видите ошибку `Resource not accessible by integration`, попробуйте один из этих workflow:

1. **`ai-simple.yaml`** - Самый простой, использует только паттерн-анализ
2. **`ai-cli.yaml`** - Использует GitHub CLI для обхода проблем с API

### Пошаговое решение

#### Шаг 1: Проверьте настройки репозитория
1. GitHub репозиторий → Settings → Actions → General
2. Workflow permissions → **Read and write permissions**
3. ✅ **Allow GitHub Actions to create and approve pull requests**
4. Сохраните изменения

#### Шаг 2: Попробуйте разные workflow

**Вариант A: Простой анализ (рекомендуется)**
```bash
# Переименуйте файлы
mv .github/workflows/ai-analysis.yaml .github/workflows/ai-analysis-backup.yaml
mv .github/workflows/ai-simple.yaml .github/workflows/ai-analysis.yaml
```

**Вариант B: GitHub CLI**
```bash
# Используйте CLI версию
mv .github/workflows/ai-analysis.yaml .github/workflows/ai-analysis-backup.yaml
mv .github/workflows/ai-cli.yaml .github/workflows/ai-analysis.yaml
```

#### Шаг 3: Создайте новый PR
- Создайте новый Pull Request
- Проверьте, что workflow запустился
- Убедитесь, что комментарии создаются

### Альтернативные решения

#### Решение 1: Personal Access Token
1. GitHub → Settings → Developer settings → Personal access tokens → Tokens (classic)
2. Создайте токен с разрешениями `repo`
3. Добавьте в секреты как `PAT_TOKEN`
4. Обновите workflow:

```yaml
env:
  GITHUB_TOKEN: ${{ secrets.PAT_TOKEN }}
```

#### Решение 2: Отключите комментарии
Если комментарии не нужны, можно просто анализировать код в логах:

```yaml
# Удалите или закомментируйте секцию "Final Summary"
# - name: Final Summary
#   if: always()
#   uses: actions/github-script@v7
```

#### Решение 3: Используйте только паттерн-анализ
Самый надежный вариант - использовать только локальный анализ без внешних API:

```yaml
# В workflow используйте только функцию simple_analysis()
# Удалите вызовы внешних API (Hugging Face, Replicate, Ollama)
```

### Проверка работоспособности

1. **Проверьте логи**: GitHub репозиторий → Actions → выберите workflow
2. **Ищите ошибки**: Обычно проблемы видны в логах
3. **Проверьте разрешения**: Убедитесь, что workflow имеет нужные права

### Частые проблемы

#### Проблема: "No C++ files found"
**Решение**: Убедитесь, что в PR есть изменения в `.cpp`, `.h`, `.hpp`, `.cc`, `.cxx` файлах

#### Проблема: "GITHUB_TOKEN not available"
**Решение**: Проверьте, что токен передается в workflow:
```yaml
env:
  GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
```

#### Проблема: "Permission denied"
**Решение**: Добавьте нужные разрешения:
```yaml
permissions:
  contents: read
  pull-requests: write
  issues: write
```

### Рекомендации

1. **Начните с простого**: Используйте `ai-simple.yaml` для тестирования
2. **Проверьте настройки**: Убедитесь, что разрешения настроены правильно
3. **Используйте логи**: Всегда проверяйте логи для диагностики проблем
4. **Тестируйте постепенно**: Добавляйте сложные функции по одной

---

**Если ничего не помогает**: Используйте `ai-simple.yaml` - он работает только с паттерн-анализом и не требует внешних API или сложных разрешений.