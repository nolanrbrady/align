# This file is responsible for configuring your application
# and its dependencies with the aid of the Mix.Config module.
#
# This configuration file is loaded before any dependency and
# is restricted to this project.
use Mix.Config

# General application configuration
config :align,
  ecto_repos: [Align.Repo]

# Configures the endpoint
config :align, Align.Endpoint,
  url: [host: "localhost"],
  secret_key_base: "nMk36Jqs48vksfJjLAlHt5DgYi28XhFxEuaxj2Ex5LOHA0IRiJSDaMJ8D1J9sw/I",
  render_errors: [view: Align.ErrorView, accepts: ~w(json)],
  pubsub: [name: Align.PubSub,
           adapter: Phoenix.PubSub.PG2]

# Configures Elixir's Logger
config :logger, :console,
  format: "$time $metadata[$level] $message\n",
  metadata: [:request_id]

# Import environment specific config. This must remain at the bottom
# of this file so it overrides the configuration defined above.
import_config "#{Mix.env}.exs"
