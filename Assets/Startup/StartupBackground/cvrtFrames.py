import subprocess

start_str = "frame_"
end_str = "_delay-0.12s.gif"

for i in range(5):
    name = "frame" + str(i) + ".png"
    # convert dragon_sm.gif    -resize 64x64  resize_dragon.gif
    subprocess.run(["convert", name, "-resize", "1500x800!", name])
