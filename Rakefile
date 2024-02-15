# frozen_string_literal: true

require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:test) do |task|
  task.pattern = [
    "test/e2e/spec/corner_cases_spec.rb",
    "test/e2e/spec/error_cases_spec.rb",
    "test/e2e/spec/checker_spec.rb",
  ]
end

task(:performance) do
  ruby "test/e2e/performance.rb"
end

task default: [:performance]
