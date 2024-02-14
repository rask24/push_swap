# frozen_string_literal: true

require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:test) do |task|
  task.pattern = [
    "test/e2e/spec/corner_cases_spec.rb",
    "test/e2e/spec/error_cases_spec.rb",
  ]
end

RSpec::Core::RakeTask.new(:performance) do |task|
  task.pattern = [
    "test/e2e/spec/performance_spec.rb",
  ]
end
