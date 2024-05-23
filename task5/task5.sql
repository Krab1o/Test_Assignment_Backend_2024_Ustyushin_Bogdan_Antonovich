CREATE TABLE Departments
(
    ID		        int IDENTITY(1,1) NOT NULL CONSTRAINT PK_Departments PRIMARY KEY,
    OCCUPATION	    nvarchar(30) NOT NULL
)

CREATE TABLE Users
(
    ID		        int IDENTITY(1,1) NOT NULL CONSTRAINT PK_Users PRIMARY KEY,
    SURNAME		    nvarchar(40) NOT NULL,
    DEPARTMENT_ID	int FOREIGN KEY REFERENCES Departments(ID) NOT NULL,
    SALARY		    int NOT NULL
)

INSERT INTO Departments (OCCUPATION)
VALUES	('Backend'),
        ('DevOps'),
        ('Android'),
        ('iOS');
        
INSERT INTO Users (SURNAME, DEPARTMENT_ID, SALARY)
VALUES  ('Алексеев', 3, 50000),
	    ('Петрухин', 3, 60000),
        ('Есенин', 2, 70000),
        ('Маяковский', 1, 80000),
        ('Нортон', 4, 90000),
        ('Антропов', 1, 100000),
        ('Андреев', 4, 110000),
        ('Силантьев', 1, 120000);
		