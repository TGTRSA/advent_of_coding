

dial_rotations = ['L68', 'L30','R48', 'L5', 'R60', 'L55', 'L1', 'L99', 'R14', 'L82']



def rotate(dial_rotations=dial_rotations):
    inital_value = 50
    values = []
    print(f"[^_^] The dial starts at {inital_value}")
    
    for char, rotation in enumerate(dial_rotations):
        operation = rotation[0]
        
        if len(rotation)==3:
                rotation_integer = int(f"{rotation[1]}" + f"{rotation[2]}")
        else: 
                rotation_integer = int(f"{rotation[1]}")
        
        #delta_rotation = inital_value-rotation_integer
        
    
        if operation == 'L':   
            current_value = inital_value - rotation_integer
            if current_value < 0:
                current_value+=100
        elif operation == 'R':
            current_value = inital_value + rotation_integer
            if current_value > 100:
                current_value-=100
        if current_value  == 100:
            current_value = 0
        inital_value = current_value
        values.append(inital_value)
        print(f"The dial is rotated {rotation} to point {current_value}")
    return values


def find_zeroes(values):
    counter = 0
    for char in range(len(values)):
        if values[char] ==  0:
            counter+=1

    print(f"The password is {counter}")
            
if __name__ == '__main__':
    values = rotate()
    find_zeroes(values)
