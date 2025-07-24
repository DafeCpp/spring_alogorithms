# 🔐 Настройка разрешений для GitHub Actions

## Проблема
Если вы видите ошибку `Resource not accessible by integration`, это означает, что GitHub Actions не имеет достаточных разрешений для работы с репозиторием.

## Решение

### Шаг 1: Настройка разрешений в репозитории

1. Перейдите в ваш GitHub репозиторий
2. Нажмите на вкладку **Settings**
3. В левом меню выберите **Actions** → **General**
4. Прокрутите вниз до раздела **Workflow permissions**
5. Выберите **Read and write permissions**
6. Поставьте галочку **Allow GitHub Actions to create and approve pull requests**
7. Нажмите **Save**

### Шаг 2: Проверка разрешений в workflow

Убедитесь, что в файлах `.github/workflows/ai-analysis.yaml` и `.github/workflows/ai-cloud-analysis.yaml` есть следующие разрешения:

```yaml
permissions:
  contents: read
  pull-requests: write
  issues: write
  actions: read
  id-token: write
```

### Шаг 3: Проверка токена

GitHub Actions использует автоматически созданный токен `GITHUB_TOKEN`. Убедитесь, что он доступен в workflow:

```yaml
env:
  GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
```

## Альтернативное решение

Если проблема не решается, можно создать Personal Access Token:

1. Перейдите в GitHub → Settings → Developer settings → Personal access tokens → Tokens (classic)
2. Создайте новый токен с разрешениями:
   - `repo` (полный доступ к репозиторию)
   - `write:packages` (если нужно)
3. Добавьте токен в секреты репозитория как `PAT_TOKEN`
4. Обновите workflow:

```yaml
env:
  GITHUB_TOKEN: ${{ secrets.PAT_TOKEN }}
```

## Проверка

После настройки:
1. Создайте новый Pull Request
2. Проверьте, что AI анализ запустился
3. Убедитесь, что комментарии создаются без ошибок

## Логи

Если проблема остается, проверьте логи в:
1. GitHub репозиторий → Actions
2. Выберите workflow
3. Просмотрите детальные логи ошибки

---

**Примечание**: Разрешения `issues: write` необходимы для создания комментариев в Pull Requests, так как GitHub API рассматривает PR как issues.