# Fitness Club Management System
### Abstract
This Fitness Club Management System basically was implemented as a CURD framework. This program manages the information of the people in the Fitness Club. First of all, people consisted of a name, age, gender, and start(registration) date and end(expiration) date. You can create, read, update, delete the information of people and additionally, you can sort by age and you can give a service(extends the end date) to all members.

### Function descriptions

#### 1. load_from_txt 
>  receive a text file name, and takes the data from the text file. if there’s a person in array, It will be append (no overwrite). if text file does not exist, the program will be exited.

#### 2. add_a_record()  
> receive the person information like name, gender, age, date and put person in the array.

#### 3. search() 
> receive person’s name as an input and show all the information of the person to standard output.

#### 4. overwrite_from_txt() 
> receive the text file name, and takes the data from the text file. if there’s a person in the array. It will be overwritten.

#### 5. save_to txt() 
> receive the text file name, and save all of the information to the txt file.

> #### 6. update_date() 
>> receive the person’s name, date and they update it.

#### 7. delete() 
> receive the person’s name and initializes person’s information.

#### 8. defragment() 
> finds characters named null in the array. and also move the array to the end of the array.

#### 9. sort() 
> it automatically arranges in order of age.

#### 10. service() 
> receive how many months extend. and extends the expiration date for everyone.
