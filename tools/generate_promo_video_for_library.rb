#!/usr/bin/ruby

r = %r{/\*\*.*?\n\}}m
system "rm imgs/*; rm vid_images/*; mkdir imgs -p; mkdir vid_images -p;"

File.read("funcs_c").scan(r).shuffle.each_with_index do |i, n|
  if i.chars.size > 3000
    File.write "imgs/funcs#{n}.html", i
  end
end

system " ./make_image_of_docs video; cp imgs/*.png vid_images"

system "rm *.mp4 *.png;"

system "for i in C D E; do
./gen_video_new --start-time=203  out${i}.mp4 20 1080 1920 #{Dir.home}/Downloads/${i}.mp3 vid_images 1
done
rm imgs/*; rm vid_images/*"
