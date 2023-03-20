# script to print the hangman at current number of tries

def print_hangman(tries_left):

    # draw body parts via strings
    head = " 0\n"
    body = "|"
    arm1 = "/"
    arm2 = "\\"
    leg1 = "\n/"
    leg2 = " \\"

    limbs = ""
    if tries_left < 6:
        limbs += head
    if tries_left < 5:
        limbs += arm1
    if tries_left < 4:
        limbs += body
    if tries_left < 3:
        limbs += arm2
    if tries_left < 2:
        limbs += leg1
    if tries_left < 1:
        limbs += leg2
    
    if limbs == "":
        print()
    else:
        print(limbs)
