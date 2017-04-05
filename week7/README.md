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
	
	operator<<
	operator>>
		
