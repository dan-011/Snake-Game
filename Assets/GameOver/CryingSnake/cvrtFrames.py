import subprocess

nameStart = "cFrame"
nameEnd = "_transparent.png"
for i in range(19):
    origFilename = nameStart + str(i) + nameEnd
    newFilename = "frame" + str(i) + ".png"
    subprocess.run(["mv", origFilename, newFilename])