import tkinter as tk
from tkinter import filedialog
from tkinter import ttk

# Глобальная переменная для хранения текста из файла
file_text = ""

# Функция для лексического анализа текста (не изменяется)
def lexical_analysis(text):
    lexemes = []
    tokens = text.split()  # Разбиваем текст на токены (пробел как разделитель)

    for token in tokens:
        if token == "for":
            lexemes.append(("FOR", "for"))
        elif token == "do":
            lexemes.append(("DO", "do"))
        elif token == "{":
            lexemes.append(("LBRACE", "{"))
        elif token == "}":
            lexemes.append(("RBRACE", "}"))
        elif token == ":=":
            lexemes.append(("ASSIGN", ":="))
        elif token in ("<", ">", "="):
            lexemes.append(("COMPARISON", token))
        elif token.startswith("0x") and all(c in "0123456789ABCDEFabcdef" for c in token[2:]):
            lexemes.append(("HEX_NUMBER", token))
        elif token.isalpha() and token.isalnum():
            lexemes.append(("IDENTIFIER", token))

    return lexemes

# Функция для открытия файла и обновления текста во вкладке "Исходный файл" (обновлена)
def open_file():
    global file_text
    file_path = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
    if file_path:
        with open(file_path, "r") as file:
            file_text = file.read()
            file_text_widget.delete("1.0", "end")  # Очищаем текстовое поле
            file_text_widget.insert("1.0", file_text)  # Вставляем текст из файла
            analyze_button.config(state="normal")  # Активируем кнопку "Запустить анализ"

            # Очищаем таблицу лексем при каждом открытии нового файла
            lexeme_table.delete(*lexeme_table.get_children())

# Функция для запуска лексического анализа и отображения результатов во вкладке "Таблица лексем" (обновлена)
def analyze_text():
    lexemes = lexical_analysis(file_text)
    display_lexemes(lexemes)
    # Переключаемся на вкладку "Таблица лексем" после анализа
    notebook.select(lexeme_tab)

# Функция для отображения результатов лексического анализа в таблице лексем
def display_lexemes(lexemes):
    lexeme_table.delete(*lexeme_table.get_children())  # Очистка таблицы перед обновлением
    for i, lexeme in enumerate(lexemes, start=1):
        lexeme_table.insert("", "end", values=(i, lexeme[0], lexeme[1]))

# Функция для завершения работы программы
def exit_program():
    root.destroy()

# Создаем основное окно
root = tk.Tk()
root.title("Лексический анализатор")

# Создаем вкладки
notebook = ttk.Notebook(root)
notebook.pack(padx=10, pady=10)

# Вкладка "Исходный файл"
file_tab = ttk.Frame(notebook)
notebook.add(file_tab, text="Исходный файл")

# Кнопка для открытия файла (улучшенный стиль)
open_button = tk.Button(file_tab, text="Открыть файл", command=open_file, padx=10, pady=5)
open_button.pack(pady=10)

# Текстовое поле для отображения текста файла
file_text_widget = tk.Text(file_tab, wrap=tk.WORD, width=40, height=15)
file_text_widget.pack(padx=20, pady=10)

# Кнопка "Запустить анализ" (активируется после загрузки файла)
analyze_button = tk.Button(file_tab, text="Запустить анализ", command=analyze_text, padx=10, pady=5, state="disabled")
analyze_button.pack(pady=10)

# Вкладка "Таблица лексем"
lexeme_tab = ttk.Frame(notebook)
notebook.add(lexeme_tab, text="Таблица лексем")

# Создаем таблицу лексем
lexeme_table = ttk.Treeview(lexeme_tab, columns=("No.", "Lexeme", "Value"), show="headings", height=15)
lexeme_table.heading("No.", text="№")
lexeme_table.heading("Lexeme", text="Лексема")
lexeme_table.heading("Value", text="Значение")
lexeme_table.pack(padx=20, pady=10)

# Кнопка "Завершить работу программы"
exit_button = tk.Button(root, text="Завершить работу программы", command=exit_program)
exit_button.pack(pady=10)

root.mainloop()
