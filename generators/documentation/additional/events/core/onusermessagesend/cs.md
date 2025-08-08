> [!note]
> The methods to get the clients are preset in UserMessage class: AddClient, RemoveClient, ClearClients, AddClients and GetClients.

#### How can I stop the execution of a User Message?
Simply return `EventResult.Stop` and it will be blocked.