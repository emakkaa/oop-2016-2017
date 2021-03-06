# Упражнение 8

## Задача 1. Динамичен масив

Динамичният масив е масив с променлив размер, позволяващ
произволен достъп до свой елемент и добавяне и премахване на елементи.
За разлика от обикновения масив, който може
да побере само фиксиран брой елементи, динамичният масив може да
увеличава капацитета си при добавяне на нови елементи.

Да се имплементира структурата от данни динамичен масив от цели числа.

За целта да се напише клас `DynamicArray`, който да има следните член-данни:

- `int* elements` - масив от всички елементи
- `int size` - текущ брой елементи в масива
- `int capacity` - текущ максимален брой елементи, които могат да се поберат
в масива; това е капацитетът на динамичния масив

Напишете конструктор по подразбиране за класа `DynamicArray`, който
инициализара празен динамичен масив с капацитет 8.

Реализирайте следните публични методи на класа `DynamicArray`:

- `int getSize();` - връща броя елементи в масива
- `int getAt(int index);` - достъп до елемент в масива на позиция `index`
(тоест методът да връща елемента в масива на позиция `index`)
- `void addAtEnd(int element);` - добавяне на елемент след
последния елемент на масива
- `void removeLast();` - премахване на последния елемент от масива
- `void addAt(int element, int index);` - добавяне на елемент в масива
на позиция `index`
- `void removeAt(int index);` - премахване на елемент от масива
на позиция `index`

При достигане на капацитета на динамичния масив, да се преоразмерява масива,
като новият капацитет да бъде два пъти по-голям от стария.

Да се напише "голяма четворка" за класа `DynamicArray`.
