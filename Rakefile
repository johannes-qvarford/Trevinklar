srcs = Dir.glob("*.cpp")
objs = srcs.map{|s| s.gsub(".cpp", ".o")}
bin = "Trevinklar"

task :default => bin

task bin => objs do |t|
	sh "g++ -o #{t.name} #{t.prerequisites.join(' ')}"
end

rule ".o" => [".cpp"] do |t|
	sh "g++ -c -o #{t.name} #{t.source}"
end
