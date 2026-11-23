import pandas as pd

cols = ['ID', 'Фильм', 'Кинотеатр', 'Цена', 'Дата']
df = pd.read_csv(r'C:\Users\Student\Documents\iutinrup11\техник.csv', sep=';', encoding='utf-8', names=cols)

cinema = input("Введите кинотеатр для поиска: ")
found = df[df['Кинотеатр'] == cinema]
print("\n--- Шаг 1: Найденные записи ---")
print(found.to_string(index=False))

field = input("\nВведите поле для сортировки (ID, Фильм, Кинотеатр, Цена, Дата): ").strip().capitalize()
if field == 'Id':
    field = 'ID'

print("\n--- Шаг 2.1: По возрастанию ---")
print(found.sort_values(by=field, ascending=True).to_string(index=False))

print("\n--- Шаг 2.2: По убыванию ---")
print(found.sort_values(by=field, ascending=False).to_string(index=False))