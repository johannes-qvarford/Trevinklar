srcs = Dir.glob("*.cpp")
libs = ["sfml-graphics", "sfml-system", "sfml-window"]
bin = "Trevinklar"

ldflags = libs.inject ("") {|s,l| s + " -l" + l}
objs = srcs.map{|s| s.gsub(".cpp", ".o")}

task :default => bin

task bin => objs do |t|
	sh "g++ -o #{t.name} #{t.prerequisites.join(' ')} #{ldflags}"
end

rule ".o" => [".cpp"] do |t|
	sh "g++ -c -o #{t.name} #{t.source}"
end
