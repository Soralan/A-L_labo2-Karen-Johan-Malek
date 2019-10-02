import my_video

choice = 0

video = my_video.openVideo()

while choice != "4":

	print("""
********************
1. play-pause
2. accelerer
3. retour en arriere
4. quitter
*********************
	""")

	choice = input("choix: ")

	if choice == "1":
		my_video.playPause(video)
	elif choice == "2":
		my_video.acceleration(video)
	elif choice == "3":
		my_video.goBackToStart(video)
	elif choice == "4":
		print("quitter")
	else:
		print("mauvaise entre")
		