def find_min_max_indexes(arr):
    # Инициализируем переменные для хранения индексов минимального и максимального элементов
    min_index, max_index = 0, 0
    min_value, max_value = arr[0], arr[0]  # Инициализируем переменные значением первого элемента

    for i in range(len(arr)):
        if arr[i] < min_value:
            min_value = arr[i]
            min_index = i
        if arr[i] > max_value:
            max_value = arr[i]
            max_index = i

    return min_index, max_index

def sum_between_min_max(arr):
    min_index, max_index = find_min_max_indexes(arr)
    if min_index > max_index:
        min_index, max_index = max_index, min_index  # Меняем местами, чтобы min_index < max_index

    # Вычисляем сумму элементов между min_index и max_index
    total = sum(arr[min_index + 1 : max_index])

    return total

# Пример использования
n = int(input("Введите количество элементов массива: "))
arr = []
for i in range(n):
    arr.append(float(input(f"Введите элемент {i+1}: ")))

result = sum_between_min_max(arr)
print(f"Сумма элементов между минимальным и максимальным элементами: {result}")
