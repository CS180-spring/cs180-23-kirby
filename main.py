# having data stored in user input

songTitle = input("Enter song title: ")
songBy = input("Enter artist of song: ")

while True:
    streamInput = input("Enter number of streams: ")
    if streamInput.isdigit():
        streamNum = streamInput
        break
    else:
        print("That was not a valid number. Please try again.")


print(songTitle + " by " + songBy + " has " + streamNum + " streams ")
