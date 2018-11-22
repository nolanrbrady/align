defmodule Align.Router do
  use Align.Web, :router

  pipeline :api do
    plug :accepts, ["json"]
  end

  scope "/api", Align do
    pipe_through :api
  end
end
