# frozen_string_literal: true

require "open3"

def execute_push_swap(*args)
  stdout, stderr, status = Open3.capture3("./push_swap #{args.join(" ")}")
  [stdout, stderr, status]
end

def execute_checker(*args)
  stdout, stderr, status = Open3.capture3("./push_swap #{args.join(" ")} | ./checker #{args.join(" ")}")
  [stdout, stderr, status]
end
