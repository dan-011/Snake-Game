import subprocess

for i in range(19):
    filename = "frame" + str(i) + ".png"
    subprocess.run(["convert", filename, "-resize", "300x384", filename])