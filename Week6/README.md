#Работа с оператори 
class Dog

	char* dogName;
	
	Dog();
	Dog(char* newName);
	Dog(const Dog& newDog); //frankenstein
	Dog& operator=(const Dog& other) 
	~Dog();

	void setDogName(char* name);
	char* getDogName() const;


class DogShelter

	Dog* dogs;
    int numDogs;
	char* shelterName;
	DogShelter();
	DogShelter(char* name);
	DogShelter(const DogShelter& other);
	DogShelter& operator=(const DogShelter &other);
	~DogShelter();

	void setName(char* newName);
	char* getName() const;

	Dog operator[](int index);
	Dog getDog(int index);

		operator<
		operator>
		operator<=
		operator>=
		operator==
		operator!=
<<<<<<< HEAD

		operator +=
		operator -=

		operator++ //prefix3
		operator++ //postfix
		
		ostream &operator<< ()
		osteram &operator>>
=======
	
	operator<<
	operator>>
>>>>>>> 248d9bc58a4708e9865d6d58773e8c9b810de867
		
