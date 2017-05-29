Да се реализират следните класове:

Клас Phone, съдържащ следните характеристики:
- марка и модел(препоръчително char*);
- памет(количество в MB);
- свободна памет;
- дали е touchscreen;
- дълъжина на диагонала на дисплея в сантиметри;
- тегло;
- издръжливост на батерията в часове;
- "количество" батерия в текущия момент в проценти.

Да се напише Голямата четворка за класа,  както и следните методи:

- метод, който отпечатва информацията за телефона;
- метод, който приема като аргументи брой минути и процент на зареждане на минута и добавя към текущото "количество" батерия съответните проценти;
- метод, който приема като аргумент процент батерия, който трябва да бъде изваден от текущото количество батерия.


Клас Camera със следните характеристики:

- резолюция в мегапиксели;
- дали има светкавица;
- среден размер на снимка, направена без светкавица(по отношение на памет, в MB);
- среден размер на снимка, направена със светкавица(ако камерата няма светкавица, този размер е 0).

Да се напишат необходимите компоненти от Голямата четворка, както и метод, отпечатва характеристиките на камерата.


Клас CameraPhone, наследяващ Phone и Camera. Освен това, той добавя и 

- минимално количество батерия, необходимо за да може да работи камерата;
- количество батерия, което отнема направата на една снимка без светкавица;
- количество батерия, което отнема направата на една снимка без светкавица(ако камерата няма светкавица, тази стойност е 0).

Да се напише Голямата четворка за този клас.Да се добавят и следните методи:

- метод, отпечатващ характеристиките;
- метод, определящ колко най-много на брой снимки могат да се направят с този телефон спрямо свободната му памет;
- метод, представляващ правене на снимка, приемащ като аргумент булева стойност в зависимост от това дали снимката се прави със или без светкавица. Ако камерата няма светкавица, стойността на този аргумент се игнорира. Методът изважда съответата памет от свободната памет на телефона и съответното количество батерия от текущото количество батерия.

